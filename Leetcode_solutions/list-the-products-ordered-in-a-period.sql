SELECT P.product_name as product_name, SUM(O.unit) as unit
FROM Products as P
JOIN Orders as O ON P.product_id = O.product_id
WHERE LEFT(O.order_date, 7) = '2020-02'
GROUP BY P.product_name
HAVING SUM(O.unit) >= 100;