-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Understanding what happened
SELECT * FROM crime_scene_reports WHERE year = '2023' AND month = 7 AND street = 'Humphrey Street';
-- Theft happened at 1015 at bakery. 3 witnesses mentioned the bakery

-- Check interview logs
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day = 28;
-- within 10 minutes of the theft, so 1015 - 1025
-- earlier that morning the theif was at ATM on leggett street. Eugene recognises him
-- 



-- checking bakery logs on the 28th, manually checking aruond 1015
SELECT * FROM bakery_security_logs WHERE year = '2023' AND month = 7 AND day = 28;
-- afew cars R3G7486 13FNH73 5P2BI95

