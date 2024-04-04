-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Understanding what happened
SELECT * FROM crime_scene_reports WHERE year = '2023' AND month = 7 AND street = 'Humphrey Street';
-- Theft happened at 1015 at bakery. 3 witnesses mentioned the bakery

-- Check interview logs
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;
-- within 10 minutes of the theft, so 1015 - 1025, he got into a car n left
-- earlier that morning the theif was at ATM on leggett street. Eugene recognises him
-- before he left, 1015 - 1025 he called someone, less then a minute to buy a flight ticket. flight on 29th, earliest flight

-- checking bakery logs on the 28th, manually checking aruond 1015
SELECT * FROM bakery_security_logs WHERE year = '2023' AND month = 7 AND day = 28;
-- afew cars 5P2BI95 94KL13X 6P58WS2 4328GD8 G412CB7 L93JTIZ 322W7JE 0NTHK55



-- checking ATM
SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 and day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- account numbers
-- checking against bank details
SELECT people.name FROM people, bank_accounts WHERE people.id = bank_accounts.person_id AND bank_accounts.account_number IN
    (SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 and day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
-- returns the people who were at the ATM

-- checking call logs
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;
-- gives me callers and receivers numbers


