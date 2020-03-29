-- 난이도가 조금 있었다.
SELECT HOUR(DATETIME) AS HOUR, count(DATETIME) as count from animal_outs where HOUR(datetime) >=9 and hour(datetime)<=19 group by HOUR(DATETIME) 