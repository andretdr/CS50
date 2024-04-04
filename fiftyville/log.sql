-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Understanding what happened
SELECT * FROM crime_scene_reports WHERE year = '2023' AND month = 7 AND street = 'Humphrey Street';
-- Theft happened at 1015 at bakery. 3 witnesses mentioned the bakery

-- Check interview logs
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;
-- within 10 minutes of the theft, so 1015 - 1025, he got into a car n left
-- earlier that morning the theif was at ATM on leggett street. Eugene recognises him
-- before he left, 1015 - 1025 he called someone, less then a minute to buy a flight ticket. flight on 29th, earliest flight out of fiftyville

-- checking bakery logs on the 28th, manually checking aruond 1015
SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25;
-- checking against people log
SELECT name FROM people WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = '2023' AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25);

-- checking ATM
SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 and day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
-- account numbers
-- checking against bank details
SELECT people.name FROM people, bank_accounts WHERE people.id = bank_accounts.person_id AND bank_accounts.account_number IN
    (SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 and day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
-- returns the people who were at the ATM

-- checking call logs
SELECT caller FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;
-- selecting the people who were calling on the day, less than 1 minute
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60);


-- airport flight log
SELECT * FROM flights, airports WHERE flights.origin_airport_id = airports.id AND year = 2023 AND month = 7 AND day = 29 AND airports.city = 'Fiftyville' ORDER BY flights.hour
ASC, flights.minute ASC;
-- dest airport id is 4

