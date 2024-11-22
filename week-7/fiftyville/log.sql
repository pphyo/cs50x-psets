-- Keep a log of any SQL queries you execute as you solve the mystery.

--1. Pull the crime scene report for the date and location of the theft
SELECT id, description FROM crime_scene_reports
    WHERE street = "Humphrey Street" AND day = 28 AND month = 07 AND year = 2021;
--theft at 10:15 am/at Humphrey Street bakery/3 witnesses/ALL mentions the bakery
--littering at 16:36, no known witnesses. (Irrelevant?)


--2. Pull interview reports of (3 witnesses) from TABLE interviews, to get witnesses name and transcript
