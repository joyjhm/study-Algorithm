SELECT ANIMAL_ID, AI.NAME
FROM ANIMAL_INS AS AI
INNER JOIN ANIMAL_OUTS AS AO USING(ANIMAL_ID)
WHERE AI.DATETIME > AO.DATETIME
ORDER BY AI.DATETIME ASC;