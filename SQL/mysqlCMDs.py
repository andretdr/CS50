SHOW DATABASES;
USE <database name>;
DESCRIBE <table name>;

UPDATE (fin_holdings INNER JOIN fin_symbs ON fin_holdings.symb_id = fin_symbs.id) 
SET fin_holdings.quantity = %s, fin_holdings.avgcost = %s 
WHERE fin_holdings.user_id = %s AND fin_symbs.symb = %s"


