-- Keep a log of any SQL queries you execute as you solve the mystery.
/* Check all table available */
.table

/* Checking the crime scene */
.schema crime_scene_reports -- checking values

SELECT *
  FROM crime_scene_reports -- make table of the report

SELECT *
  FROM crime_scene_reports -- make table of the report using the specific date
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time.
-- Each of their interview transcripts mentions the bakery.

/* Checking content of the interview */
.schema interviews

SELECT *
  FROM interviews
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND transcript LIKE '%bakery%';

/*
Ruth
Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery
parking lot and drive away. If you have security footage from the bakery parking lot,
you might want to look for cars that left the parking lot in that time frame.

Eugene
I don't know the thief's name, but it was someone I recognized. Earlier this morning,
before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw
the thief there withdrawing some money.

Raymond
As the thief was leaving the bakery, they called someone who talked to them for less
than a minute. In the call, I heard the thief say that they were planning to take the
earliest flight out of Fiftyville tomorrow. The thief then asked the person on the
other end of the phone to purchase the flight ticket.
*/

/* 1- Checking Bakery security log to establish suspect and car plate number */
.schema bakery_security_logs

SELECT *
  FROM bakery_security_logs -- Checking on the car entering and exiting the parking lot during the incident
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND hour BETWEEN 9 AND 11;

+------+--------+----------+---------------+
| hour | minute | activity | license_plate |
+------+--------+----------+---------------+
| 9    | 14     | entrance | 4328GD8       |
| 9    | 15     | entrance | 5P2BI95       |
| 9    | 20     | entrance | 6P58WS2       |
| 9    | 28     | entrance | G412CB7       |
| 10   | 8      | entrance | R3G7486       |
| 10   | 14     | entrance | 13FNH73       |
| 10   | 16     | exit     | 5P2BI95       |
| 10   | 18     | exit     | 94KL13X       |
| 10   | 18     | exit     | 6P58WS2       |
| 10   | 19     | exit     | 4328GD8       |
| 10   | 20     | exit     | G412CB7       |
| 10   | 21     | exit     | L93JTIZ       |
| 10   | 23     | exit     | 322W7JE       |
| 10   | 23     | exit     | 0NTHK55       |
| 10   | 35     | exit     | 1106N58       |
| 10   | 42     | entrance | NRYN856       |
| 10   | 44     | entrance | WD5M8I6       |
| 10   | 55     | entrance | V47T75I       |
| 11   | 6      | entrance | 4963D92       |
| 11   | 13     | entrance | C194752       |
| 11   | 52     | entrance | 94MV71O       |
+------+--------+----------+---------------+

-- Including name with suspect's car
/* Finding the name and number plate for car exiting */
SELECT name, hour, minute, activity, people.license_plate
  FROM bakery_security_logs -- Checking on the car entering and exiting the parking lot during the incident
  JOIN people ON people.license_plate = bakery_security_logs.license_plate
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND hour = 10
   AND minute >= 15 AND minute <= 25
   AND activity = 'exit';

+---------+------+--------+----------+---------------+
|  name   | hour | minute | activity | license_plate |
+---------+------+--------+----------+---------------+
| Vanessa | 10   | 16     | exit     | 5P2BI95       |
| Bruce   | 10   | 18     | exit     | 94KL13X       |
| Barry   | 10   | 18     | exit     | 6P58WS2       |
| Luca    | 10   | 19     | exit     | 4328GD8       |
| Sofia   | 10   | 20     | exit     | G412CB7       |
| Iman    | 10   | 21     | exit     | L93JTIZ       |
| Diana   | 10   | 23     | exit     | 322W7JE       |
| Kelsey  | 10   | 23     | exit     | 0NTHK55       |
+---------+------+--------+----------+---------------+

/* 2- Identify the suspect who use the ATM */

/* Check the atm transcation happen at Leggett Street at the date 28/7/2023 */
SELECT *
  FROM atm_transactions
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street';

+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 275 | 86363979       | 2023 | 7     | 28  | Leggett Street | deposit          | 10     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

/* Joining atm_transactions, bank_account and people so we can identify who have done transcation here */
SELECT people.name, atm_transactions.account_number, atm_transactions.amount
  FROM people
  JOIN bank_accounts ON bank_accounts.person_id = people.id
  JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND transaction_type LIKE 'withdraw'
   AND atm_location LIKE 'Leggett Street';

-- Suspects who withdrawed money on the same day as the incident
+---------+----------------+--------+
|  name   | account_number | amount |
+---------+----------------+--------+
| Bruce   | 49610011       | 50     |
| Diana   | 26013199       | 35     |
| Brooke  | 16153065       | 80     |
| Kenny   | 28296815       | 20     |
| Iman    | 25506511       | 20     |
| Luca    | 28500762       | 48     |
| Taylor  | 76054385       | 60     |
| Benista | 81061156       | 30     |
+---------+----------------+--------+

/* Checking caller and receiver within the day of the incident*/
SELECT *
  FROM phone_calls
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND duration <=60;

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2023 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2023 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
| 234 | (609) 555-5876 | (389) 555-5198 | 2023 | 7     | 28  | 60       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2023 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2023 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2023 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2023 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2023 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2023 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+

/* Find the name of caller and receiver on the same date.*/
SELECT calling.name, caller, answer.name, receiver, duration
  FROM phone_calls
  JOIN people calling ON calling.phone_number = phone_calls.caller
  JOIN people answer ON answer.phone_number = phone_calls.receiver
 WHERE year = 2023
   AND month = 7
   AND day = 28
   AND duration <=60;

+---------+----------------+------------+----------------+----------+
|  name   |     caller     |    name    |    receiver    | duration |
+---------+----------------+------------+----------------+----------+
| Sofia   | (130) 555-0289 | Jack       | (996) 555-8899 | 51       |
| Kelsey  | (499) 555-9472 | Larry      | (892) 555-8872 | 36       |
| Bruce   | (367) 555-5533 | Robin      | (375) 555-8161 | 45       |
| Kathryn | (609) 555-5876 | Luca       | (389) 555-5198 | 60       |
| Kelsey  | (499) 555-9472 | Melissa    | (717) 555-1342 | 50       |
| Taylor  | (286) 555-6063 | James      | (676) 555-6554 | 43       |
| Diana   | (770) 555-1861 | Philip     | (725) 555-3243 | 49       |
| Carina  | (031) 555-6622 | Jacqueline | (910) 555-3251 | 38       |
| Kenny   | (826) 555-1652 | Doris      | (066) 555-9701 | 55       |
| Benista | (338) 555-6650 | Anna       | (704) 555-2131 | 54       |
+---------+----------------+------------+----------------+----------+

/*4- Checking the flight information
Identifying the flight based on interview info, date = 29/7/2023
Leaving Fiftyville and bought by the receiver */
SELECT origin.abbreviation, destination.abbreviation, destination.city, hour, minute
FROM flights
JOIN airports origin ON origin.id = flights.origin_airport_id
JOIN airports destination ON destination.id = flights.destination_airport_id
 WHERE year = 2023
   AND month = 7
   AND day = 29
   AND origin.full_name LIKE '%Fiftyville Regional Airport%'
 ORDER BY hour ASC;

+--------------+--------------+---------------+------+--------+
| abbreviation | abbreviation |     city      | hour | minute |
+--------------+--------------+---------------+------+--------+
| CSF          | LGA          | New York City | 8    | 20     |
| CSF          | ORD          | Chicago       | 9    | 30     |
| CSF          | SFO          | San Francisco | 12   | 15     |
| CSF          | HND          | Tokyo         | 15   | 20     |
| CSF          | BOS          | Boston        | 16   | 0      |
+--------------+--------------+---------------+------+--------+

SELECT people.name, people.passport_number, origin.abbreviation, destination.abbreviation, destination.city, hour, minute
FROM flights
JOIN airports origin ON origin.id = flights.origin_airport_id
JOIN airports destination ON destination.id = flights.destination_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
 WHERE year = 2023
   AND month = 7
   AND day = 29
   AND origin.full_name LIKE '%Fiftyville Regional Airport%'
 ORDER BY hour ASC;

 +-----------+-----------------+--------------+--------------+---------------+------+--------+
|   name    | passport_number | abbreviation | abbreviation |     city      | hour | minute |
+-----------+-----------------+--------------+--------------+---------------+------+--------+
| Doris     | 7214083635      | CSF          | LGA          | New York City | 8    | 20     |
| Sofia     | 1695452385      | CSF          | LGA          | New York City | 8    | 20     |
| Bruce     | 5773159633      | CSF          | LGA          | New York City | 8    | 20     |
| Edward    | 1540955065      | CSF          | LGA          | New York City | 8    | 20     |
| Kelsey    | 8294398571      | CSF          | LGA          | New York City | 8    | 20     |
| Taylor    | 1988161715      | CSF          | LGA          | New York City | 8    | 20     |
| Kenny     | 9878712108      | CSF          | LGA          | New York City | 8    | 20     |
| Luca      | 8496433585      | CSF          | LGA          | New York City | 8    | 20     |
| Daniel    | 7597790505      | CSF          | ORD          | Chicago       | 9    | 30     |
| Carol     | 6128131458      | CSF          | ORD          | Chicago       | 9    | 30     |
| Rebecca   | 6264773605      | CSF          | ORD          | Chicago       | 9    | 30     |
| Sophia    | 3642612721      | CSF          | ORD          | Chicago       | 9    | 30     |
| Heather   | 4356447308      | CSF          | ORD          | Chicago       | 9    | 30     |
| Marilyn   | 7441135547      | CSF          | ORD          | Chicago       | 9    | 30     |
| Dennis    | 4149859587      | CSF          | SFO          | San Francisco | 12   | 15     |
| Jose      | 9183348466      | CSF          | SFO          | San Francisco | 12   | 15     |
| Jennifer  | 7378796210      | CSF          | SFO          | San Francisco | 12   | 15     |
| Brandon   | 7874488539      | CSF          | SFO          | San Francisco | 12   | 15     |
| Matthew   | 4195341387      | CSF          | SFO          | San Francisco | 12   | 15     |
| Emily     | 6263461050      | CSF          | SFO          | San Francisco | 12   | 15     |
| Douglas   | 3231999695      | CSF          | SFO          | San Francisco | 12   | 15     |
| Jordan    | 7951366683      | CSF          | SFO          | San Francisco | 12   | 15     |
| Richard   | 7894166154      | CSF          | HND          | Tokyo         | 15   | 20     |
| Thomas    | 6034823042      | CSF          | HND          | Tokyo         | 15   | 20     |
| Brooke    | 4408372428      | CSF          | HND          | Tokyo         | 15   | 20     |
| Larry     | 2312901747      | CSF          | HND          | Tokyo         | 15   | 20     |
| Steven    | 1151340634      | CSF          | HND          | Tokyo         | 15   | 20     |
| John      | 8174538026      | CSF          | HND          | Tokyo         | 15   | 20     |
| Pamela    | 1050247273      | CSF          | HND          | Tokyo         | 15   | 20     |
| Melissa   | 7834357192      | CSF          | HND          | Tokyo         | 15   | 20     |
| Gloria    | 2835165196      | CSF          | BOS          | Boston        | 16   | 0      |
| Kristina  | 6131360461      | CSF          | BOS          | Boston        | 16   | 0      |
| Douglas   | 3231999695      | CSF          | BOS          | Boston        | 16   | 0      |
| Diana     | 3592750733      | CSF          | BOS          | Boston        | 16   | 0      |
| Christian | 2626335085      | CSF          | BOS          | Boston        | 16   | 0      |
| Michael   | 6117294637      | CSF          | BOS          | Boston        | 16   | 0      |
| Ethan     | 2996517496      | CSF          | BOS          | Boston        | 16   | 0      |
| Charles   | 3915621712      | CSF          | BOS          | Boston        | 16   | 0      |
+-----------+-----------------+--------------+--------------+---------------+------+--------+

/* Only the earliest flight on 29/7/2023*/
SELECT people.name, people.passport_number, origin.abbreviation, destination.abbreviation, destination.city, hour, minute
FROM flights
JOIN airports origin ON origin.id = flights.origin_airport_id
JOIN airports destination ON destination.id = flights.destination_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
 WHERE year = 2023
   AND month = 7
   AND day = 29
   AND hour = 8
   AND minute = 20
   AND origin.full_name LIKE '%Fiftyville Regional Airport%'
 ORDER BY hour ASC;
 +--------+-----------------+--------------+--------------+---------------+------+--------+
|  name  | passport_number | abbreviation | abbreviation |     city      | hour | minute |
+--------+-----------------+--------------+--------------+---------------+------+--------+
| Edward | 1540955065      | CSF          | LGA          | New York City | 8    | 20     |
| Sofia  | 1695452385      | CSF          | LGA          | New York City | 8    | 20     |
| Taylor | 1988161715      | CSF          | LGA          | New York City | 8    | 20     |
| Bruce  | 5773159633      | CSF          | LGA          | New York City | 8    | 20     |
| Doris  | 7214083635      | CSF          | LGA          | New York City | 8    | 20     |
| Kelsey | 8294398571      | CSF          | LGA          | New York City | 8    | 20     |
| Luca   | 8496433585      | CSF          | LGA          | New York City | 8    | 20     |
| Kenny  | 9878712108      | CSF          | LGA          | New York City | 8    | 20     |
+--------+-----------------+--------------+--------------+---------------+------+--------+

/* Table comparison of suspects from each clue*/

+---------+------+--------+----------+---------------+
|  name   | hour | minute | activity | license_plate |
+---------+------+--------+----------+---------------+
| Vanessa | 10   | 16     | exit     | 5P2BI95       | non supect
| Bruce*  | 10   | 18     | exit     | 94KL13X       | 4/4 PRIME SUSPECT
| Barry   | 10   | 18     | exit     | 6P58WS2       | non suspect
| Luca    | 10   | 19     | exit     | 4328GD8       | 3/4 non caller
| Sofia   | 10   | 20     | exit     | G412CB7       | 3/4 non ATM
| Iman    | 10   | 21     | exit     | L93JTIZ       | 2/4 non caller non passport
| Diana   | 10   | 23     | exit     | 322W7JE       | 3/4 non flight
| Kelsey  | 10   | 23     | exit     | 0NTHK55       | 3/4 kelsey NON ATM
+---------+------+--------+----------+---------------+

+---------+----------------+--------+
|  name   | account_number | amount |
+---------+----------------+--------+
| Bruce*  | 49610011       | 50     |
| Diana   | 26013199       | 35     |
| Brooke  | 16153065       | 80     |
| Kenny   | 28296815       | 20     |
| Iman    | 25506511       | 20     |
| Luca    | 28500762       | 48     |
| Taylor  | 76054385       | 60     |
| Benista | 81061156       | 30     |
+---------+----------------+--------+
+---------+----------------+------------+----------------+----------+
|  name   |     caller     |    name    |    receiver    | duration |
+---------+----------------+------------+----------------+----------+
| Sofia   | (130) 555-0289 | Jack       | (996) 555-8899 | 51       |
| Kelsey  | (499) 555-9472 | Larry      | (892) 555-8872 | 36       |
| Bruce*  | (367) 555-5533 | Robin**    | (375) 555-8161 | 45       | ** MAIN ACCOMPLICE
| Kathryn | (609) 555-5876 | Luca       | (389) 555-5198 | 60       |
| Kelsey  | (499) 555-9472 | Melissa    | (717) 555-1342 | 50       |
| Taylor  | (286) 555-6063 | James      | (676) 555-6554 | 43       |
| Diana   | (770) 555-1861 | Philip     | (725) 555-3243 | 49       |
| Carina  | (031) 555-6622 | Jacqueline | (910) 555-3251 | 38       |
| Kenny   | (826) 555-1652 | Doris      | (066) 555-9701 | 55       |
| Benista | (338) 555-6650 | Anna       | (704) 555-2131 | 54       |
+---------+----------------+------------+----------------+----------+

 +--------+-----------------+--------------+--------------+---------------+------+--------+
|  name  | passport_number | abbreviation | abbreviation |     city      | hour | minute |
+--------+-----------------+--------------+--------------+---------------+------+--------+
| Edward | 1540955065      | CSF          | LGA          | New York City | 8    | 20     | ***Flying too New York City
| Sofia  | 1695452385      | CSF          | LGA          | New York City | 8    | 20     |
| Taylor | 1988161715      | CSF          | LGA          | New York City | 8    | 20     |
| Bruce* | 5773159633      | CSF          | LGA          | New York City | 8    | 20     |
| Doris  | 7214083635      | CSF          | LGA          | New York City | 8    | 20     |
| Kelsey | 8294398571      | CSF          | LGA          | New York City | 8    | 20     |
| Luca   | 8496433585      | CSF          | LGA          | New York City | 8    | 20     |
| Kenny  | 9878712108      | CSF          | LGA          | New York City | 8    | 20     |
+--------+-----------------+--------------+--------------+---------------+------+--------+
