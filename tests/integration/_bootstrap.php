<?php
// Here you can initialize variables that will for your tests
$finder = \Symfony\Component\Finder\Finder::create()->files()->name('*.php');

foreach ($finder->in(\Codeception\Configuration::dataDir().'Models') as $file) {
    require_once $file;
}

foreach ($finder->in(\Codeception\Configuration::dataDir().'Fixtures') as $file) {
    require_once $file;
}
