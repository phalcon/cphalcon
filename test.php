<?php

$path = __DIR__ . '/nikos';
$template = '<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\%ns%;

use UnitTester;

class %m%Cest
{
    /**
     * Tests Phalcon\%ns% :: %sm%()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function test%m%(UnitTester $I, $scenario)
    {
        $scenario->incomplete("Need implementation");
    }
}
';

$replace = [
    '%ns%' => '',
    '%m%'  => '',
    '%sm%' => '',
];

if (true !== file_exists($path)) {
    mkdir($path, 0777, true);
}


$classes = get_declared_classes();
$phalcon = [];

foreach ($classes as $class) {
    if (substr(strtolower($class), 0, 7) === 'phalcon' &&
        strpos($class, 'closure') === false) {
        $phalcon[] = $class;
    }
}

foreach ($phalcon as $class) {
    $file = $path . '/' . str_replace('\\', '/', $class);
    var_dump($file);
    if (true !== file_exists($file)) {
        mkdir($file, 0777, true);
    }

    $methods = get_class_methods($class);
    sort($methods);
    $replace['%ns%'] = str_replace('Phalcon\\', '', $class);
    foreach ($methods as $method) {
        $replace['%m%']  = ucfirst($method);
        $replace['%sm%'] = $method;
        $output = str_replace(array_keys($replace), array_values($replace), $template);
        file_put_contents($file . '/' . ucfirst($method) . 'Cest.php', $output);
    }
}




//var_dump($phalcon);
