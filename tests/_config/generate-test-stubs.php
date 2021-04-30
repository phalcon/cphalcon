<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

$template = '<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\%type%\%n%;

use %type%Tester;

class %m%Cest
{
    /**
     * %type% Tests %ns% :: %sm%()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  %d%
     */
    public function %nn%%m%(%type%Tester $I)
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

// Argument 1: could be "unit" or "integration" shortcut "u" or "i"
$type = ucfirst($argv[1] ?? 'unit');

// Normalize shortcut I = Integration or U = Unit
if (strlen($type) === 1) {
    $type = $type === 'I' ? 'Integration' : 'Unit';
}

$placeholders = [
    '%type%' => $type,
    '%ns%'   => '',
    '%nn%'   => '',
    '%n%'    => '',
    '%m%'    => '',
    '%sm%'   => '',
    '%d%'    => date('Y-m-d'),
];

$outputDir = dirname(__DIR__) . '/nikos/';

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
            case '__call':
                $method = 'underscoreCall';

                break;
            case '__invoke':
                $method = 'underscoreInvoke';

                break;
            case '__wakeup':
                $method = 'wakeup';

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
