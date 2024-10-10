-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Time of crime = 10:15am / Location = Humphrey Street BAKERY
SELECT description FROM crime_scene_reports
WHERE (
    year = 2021
    AND month = 7
    AND day = 28
    AND street LIKE 'Humphrey Street'
);

--Thief escaped in car between 10:15am - 10:25am / Thief withdrew money from ATM, time < 10:15am, location = Leggett Street / Thief called person A, time between 10:15am - 10:25am, duration < 1 min
--Thief and person A plans to take EARLIEST flight out on July 29 / Flight ticket purchased by person A, time > 10:15am, date < July 30
SELECT transcript FROM interviews
WHERE (
    year = 2021
    AND month = 7
    AND day = 28
);

--Obtain suspect license plates for possible thief car. Time between 10:15am - 10:25am.
SELECT * FROM bakery_security_logs
WHERE (
    year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
)
ORDER BY minute;

--Obtain names by callers with suspect license plates. Time between 10:15am - 10:25am. Duration < 1 min.
SELECT * FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE (
    bakery_security_logs.year = 2021
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute >= 15
    AND bakery_security_logs.minute <= 25
    AND phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60
);

--Include passengers of flights on July 29, sorted by flight hour and minute. Also include people who withdrew money from atm before 10:15.
--Thief is Bruce. Results are Bruce and Diana, with Bruce on the earlier flight.
SELECT name, flights.hour, flights.minute FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE (
    bakery_security_logs.year = 2021
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute >= 15
    AND bakery_security_logs.minute <= 25
    AND phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60
    AND atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw'
    AND flights.year = 2021
    AND flights.month = 7
    AND flights.day = 29
)
ORDER BY flights.hour, flights.minute;

--Obtain name of who Bruce called after leaving Bakery
SELECT name FROM people
WHERE phone_number = (
    SELECT receiver FROM people
    JOIN phone_calls ON phone_calls.caller = people.phone_number
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
    WHERE (
        bakery_security_logs.year = 2021
        AND bakery_security_logs.month = 7
        AND bakery_security_logs.day = 28
        AND bakery_security_logs.hour = 10
        AND bakery_security_logs.minute >= 15
        AND bakery_security_logs.minute <= 25
        AND phone_calls.year = 2021
        AND phone_calls.month = 7
        AND phone_calls.day = 28
        AND phone_calls.duration < 60
        AND name LIKE 'Bruce'
    )
);

--Obtain city Bruce is escaping to. Ans: New York City
SELECT city FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE name LIKE 'Bruce';

