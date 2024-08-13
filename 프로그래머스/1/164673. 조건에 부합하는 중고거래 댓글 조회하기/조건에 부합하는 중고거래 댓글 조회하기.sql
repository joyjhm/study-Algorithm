-- 코드를 입력하세요
SELECT board.TITLE, board.BOARD_ID, reply.REPLY_ID, 
    reply.WRITER_ID, reply.CONTENTS, 
    TO_CHAR(reply.CREATED_DATE, 'yyyy-mm-dd') as CREATED_DATE 
FROM USED_GOODS_BOARD board
INNER JOIN USED_GOODS_REPLY reply
ON board.BOARD_ID = reply.BOARD_ID
WHERE TO_CHAR(board.CREATED_DATE, 'yyyy-mm') = '2022-10'
ORDER BY reply.CREATED_DATE, board.TITLE;