-- 코드를 입력하세요
SELECT BOOK_ID, TO_CHAR(PUBLISHED_DATE, 'yyyy-mm-dd') as PUBLISHED_DATE
FROM BOOK
WHERE CATEGORY = '인문' and TO_CHAR(PUBLISHED_DATE, 'yyyy') = '2021'
ORDER BY PUBLISHED_DATE