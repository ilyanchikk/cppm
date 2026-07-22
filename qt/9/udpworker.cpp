#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    __serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    __serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);

    connect(__serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

}


void UDPworker::SendTimeData(const QDateTime& m_dateTime)
{
    QByteArray dataToSend;
    QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

    outStr << static_cast<int>(DatagramType::TimeType);
    outStr << m_dateTime;

    SendDatagram(dataToSend);
}


void UDPworker::SendTextData(const QByteArray& m_textData)
{
    QByteArray dataToSend;
    QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

    outStr << static_cast<int>(DatagramType::TextType);
    outStr << m_textData;

    SendDatagram(dataToSend);
}

void UDPworker::SendDatagram(const QByteArray& m_data)
{
    __serviceUdpSocket->writeDatagram(m_data, QHostAddress::LocalHost, BIND_PORT);
}

void UDPworker::readPendingDatagrams(void)
{
    while(__serviceUdpSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = __serviceUdpSocket->receiveDatagram();
        QByteArray data = datagram.data();

        QDataStream inStr(&data, QIODevice::ReadOnly);


        int type = 0;
        inStr >> type;


        if (type == DatagramType::TimeType) {
            QDateTime dateTime;
            inStr >> dateTime;
            if(dateTime.isValid()) {
                emit sig_sendTimeToGUI(dateTime);
            }
        }
        else if (type == DatagramType::TextType) {

            int payloadSize = data.size() - sizeof(int);
            if (payloadSize < 0) payloadSize = 0;

            emit sig_sendTextInfoToGUI(datagram.senderAddress(), payloadSize);
        }
    }
}
