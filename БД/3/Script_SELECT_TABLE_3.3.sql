--1 Количество исполнителей в каждом жанре.
SELECT name, count(id) FROM janre 
JOIN performers_janre ON janre.id = performers_janre.id_janre
GROUP BY janre.name;

--2 Количество треков, вошедших в альбомы 2019–2020 годов.
select count(*) from tracks
JOIN albums on tracks.id = albums.id
WHERE date_manuf >= '2019.01.01' and date_manuf <= '2020.12.31'

--3 Средняя продолжительность треков по каждому альбому.
select albums.name, avg(time) from tracks
JOIN albums on tracks.id = albums.id
GROUP BY albums.name;

--4 Все исполнители, которые не выпустили альбомы в 2020 году.
select performers.name from performers 
JOIN albums_performers on performers.id = albums_performers.id_performers
JOIN albums on albums.id = albums_performers.id_album 
WHERE date_manuf not between '2020.01.01' and '2020.12.31' 
GROUP BY performers.name;

--5 Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
SELECT collections.name, performers.name from collections
JOIN tracks_collections on tracks_collections.id_collections = collections.id
JOIN tracks on tracks_collections.id_tracks = tracks.id
JOIN albums on tracks.id_album = albums.id
JOIN albums_performers on albums_performers.id_album = albums.id
JOIN performers on albums_performers.id_performers = performers.id
WHERE performers.name = 'Баста'
GROUP BY collections.name, performers.name;
