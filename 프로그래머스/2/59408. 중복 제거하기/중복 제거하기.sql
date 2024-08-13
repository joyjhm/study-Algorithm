-- 코드를 입력하세요
SELECT COUNT(*) as count
FROM (SELECT distinct NAME FROM ANIMAL_INS)
WHERE NAME is not null