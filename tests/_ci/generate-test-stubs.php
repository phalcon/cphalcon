<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Phalcon\Text;

$template = '<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\%n%;

use UnitTester;

class %m%Cest
{
    /**
     * Tests %ns% :: %sm%()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  %d%
     */
    public function %nn%%m%(UnitTester $I)
    {
        $I->wantToTest(\'%n% - %sm%()\');

        $I->skipTest(\'Need implementation\');
    }
}
';

$allClasses     = get_declared_classes();
$phalconClasses = [];

foreach ($allClasses as $class) {
    if ('Phalcon\\' === substr($class, 0, 8)) {
        $phalconClasses[] = $class;
    }
}

$placeholders = [
    '%ns%' => '',
    '%nn%' => '',
    '%n%'  => '',
    '%m%'  => '',
    '%sm%' => '',
    '%d%'  => date('Y-m-d'),
];

$outputDir = dirname(dirname(__FILE__)) . '/nikos/';

foreach ($phalconClasses as $class) {
    $newClass = str_replace('Phalcon\\', '', $class);

    $methods = get_class_methods($class);

    sort($methods);

    foreach ($methods as $method) {
        $placeholders['%ns%'] = $class;
        $placeholders['%n%']  = $newClass;
        $placeholders['%nn%'] = lcfirst(str_replace('\\', '', $newClass));
        $placeholders['%sm%'] = $method;

        switch ($method) {
            case '__construct':
                $method = 'construct';
                break;
            case '__destruct':
                $method = 'destruct';
                break;
            case '__toString':
                $method = 'toString';
                break;
            case '__get':
                $method = 'underscoreGet';
                break;
            case '__set':
                $method = 'underscoreSet';
                break;
            case '__isset':
                $method = 'underscoreIsSet';
                break;
            case '__unset':
                $method = 'underscoreUnset';
                break;
            case '__wakeup':
                $method = 'wakeup';
                break;
            case '__set_state':
                $method = 'setState';
                break;
        }

        $placeholders['%m%'] = ucfirst($method);

        $dir = str_replace(
            '\\',
            '/',
            $outputDir . $class
        );

        @mkdir($dir, 0777, true);

        $from     = array_keys($placeholders);
        $to       = array_values($placeholders);
        $contents = str_replace($from, $to, $template);

        $fileName = str_replace(
            '\\',
            '/',
            $outputDir . $class . '/' . ucfirst($method) . 'Cest.php'
        );

        echo 'Filename: ' . $fileName . PHP_EOL;

        file_put_contents($fileName, $contents);
    }
}
