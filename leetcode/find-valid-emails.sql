SELECT user_id, email
FROM users
WHERE email ~ '^\w+@\w+.com$'
ORDER BY user_id;
