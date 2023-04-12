-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To get tables and headings of tables present in database
.schema

-- To get reports of crime that took place on July 28
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7;

-- To get transcript of the witnesses
SELECT * FROM interviews WHERE day = 28 AND month = 7;

-- To get license_plate of people who exit from courthouse between 10:15 to 10:25
SELECT hour, minute, license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND activity = "exit" AND hour = 10 AND minute <= 25;

-- To get name of those people
SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate WHERE day = 28 AND month = 7 AND activity = "exit" AND hour = 10 AND minute <= 25;

--To get name of people who withdraw money from Fifer Street atm on July 28
SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = 28 AND month = 7 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";

-- To get passport_number and phone number of people who withdraw money and leave courthouse
SELECT name, passport_number, phone_number FROM people WHERE name = "Ernest" OR name = "Russell" OR name = "Elizabeth";

-- To get id of fiftyville airport
SELECT id FROM airports WHERE city =  "Fiftyville";

--To get passengers list who took flight from fiftyville on July 29
SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE origin_airport_id = 8 AND day = 29 AND month = 7 ORDER BY hour;

-- To get city on which he has gone
SELECT city FROM airports JOIN flights ON airports.id = flights.destination_airport_id JOIN passengers ON flights.id = passengers.flight_id WHERE passport_number = 5773159633;

-- To get name of accomplice
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE caller = "(367) 555-5533" AND day = 28 AND month = 7 AND duration < 60;