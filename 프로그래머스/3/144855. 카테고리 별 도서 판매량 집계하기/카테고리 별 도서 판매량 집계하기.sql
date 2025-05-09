SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK
INNER JOIN BOOK_SALES USING(BOOK_ID)
WHERE SALES_DATE like '2022-01%'
GROUP BY CATEGORY
ORDER BY CATEGORY ASC;