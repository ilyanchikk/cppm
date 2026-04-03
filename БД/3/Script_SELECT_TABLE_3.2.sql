-- 1 Название и продолжительность самого длительного трека.
SELECT  name, time
FROM tracks
WHERE time = (SELECT MAX(time) FROM tracks);

-- 2 Название треков, продолжительность которых не менее 3,5 минут.
SELECT  name
FROM tracks
WHERE time > '00:03:50';

-- 3 Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT  name
FROM collections
WHERE date_manuf >= '2018.01.01' AND date_manuf < '2021.01.01';

-- 4 Исполнители, чьё имя состоит из одного слова.
SELECT  name
FROM performers
WHERE name NOT LIKE '% %';

-- 5 Название треков, которые содержат слова «мой» или «my».
SELECT  name
FROM tracks
WHERE name LIKE '%my%' OR name LIKE '%мой%';