--Добавляем Жанры
INSERT INTO janre (name)
VALUES ('Рок');
INSERT INTO janre (name)
VALUES ('Реп');
INSERT INTO janre (name)
VALUES ('Джаз');
INSERT INTO janre (name)
VALUES ('Шансон');

--Добавляем Исполнителей
INSERT INTO performers (name)
VALUES ('Виктор Цой');
INSERT INTO performers (name)
VALUES ('Баста');
INSERT INTO performers (name)
VALUES ('Херби Хэнкок');
INSERT INTO performers (name)
VALUES ('Михаил Круг');

--Заполняем сводную таблицу performers_janre
INSERT INTO performers_janre (id_janre,id_pefromers)
VALUES ('1', '1');
INSERT INTO performers_janre (id_janre,id_pefromers)
VALUES ('2', '2');
INSERT INTO performers_janre (id_janre,id_pefromers)
VALUES ('3', '3');
INSERT INTO performers_janre (id_janre,id_pefromers)
VALUES ('4', '4');

--Заполняем albums
INSERT INTO albums (name,date_manuf)
VALUES ('Группа крови', '01.02.1988');
INSERT INTO albums (name,date_manuf)
VALUES ('Баста 5. Часть 1', '21.04.2019');
INSERT INTO albums (name,date_manuf)
VALUES ('Takin Off', '25.10.2001');
INSERT INTO albums (name,date_manuf)
VALUES ('Жиган-Лимон', '15.06.1994');

--Заполняем albums_performers
INSERT INTO albums_performers (id_album,id_performers)
VALUES ('1', '1');
INSERT INTO albums_performers (id_album,id_performers)
VALUES ('2', '2');
INSERT INTO albums_performers (id_album,id_performers)
VALUES ('3', '3');
INSERT INTO albums_performers (id_album,id_performers)
VALUES ('4', '4');

--Заполняем tracks
INSERT INTO tracks (id_album, name, time)
VALUES ('1', 'Группа крови', '00:04:12');
INSERT INTO tracks (id_album, name, time)
VALUES ('2', 'Партизан', '00:02:42');
INSERT INTO tracks (id_album, name, time)
VALUES ('3', ' my Driftin', '00:06:58');
INSERT INTO tracks (id_album, name, time)
VALUES ('4', 'Девочка пай', '00:03:12');
INSERT INTO tracks (id_album, name, time)
VALUES ('1', 'Война', '00:04:05');
INSERT INTO tracks (id_album, name, time)
VALUES ('2', 'мой голос', '00:03:13');

--Заполняем collections
INSERT INTO collections (name, date_manuf, time)
VALUES ('Коллекция 1', '14.02.2019', '01:00:00');
INSERT INTO collections (name, date_manuf, time)
VALUES ('Коллекция 2', '1.01.1992', '00:56:10');
INSERT INTO collections (name, date_manuf, time)
VALUES ('Коллекция 3', '12.02.2023', '01:12:00');
INSERT INTO collections (name, date_manuf, time)
VALUES ('Коллекция 4', '4.05.2014', '00:30:00');

--Заполняем tracks_collections
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('1', '1');
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('2', '2');
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('3', '3');
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('4', '4');
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('5', '1');
INSERT INTO tracks_collections (id_tracks,id_collections)
VALUES ('6', '2');