SHOW DATABASES;
USE <database name>;
DESCRIBE <table name>;

UPDATE (fin_holdings INNER JOIN fin_symbs ON fin_holdings.symb_id = fin_symbs.id) 
SET fin_holdings.quantity = %s, fin_holdings.avgcost = %s 
WHERE fin_holdings.user_id = %s AND fin_symbs.symb = %s"

"SELECT fin_holdings.avgcost, fin_holdings.quantity, fin_symbs.symb, fin_users.cash 
FROM ((fin_holdings INNER JOIN fin_users ON fin_holdings.user_id = fin_users.id) 
      INNER JOIN fin_symbs ON fin_holdings.symb_id = fin_symbs.id) 
WHERE fin_users.username = %s AND fin_symbs.symb = %s"
