<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;

use function sleep;
use function strpos;

class StartFinishCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Profiler\Profiler :: start()/finish()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerStartFinish(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Profiler\Profiler - start()/finish()');

        $profiler = new Profiler();

        $profiler
            ->setActive(true)
            ->start('my-method')
        ;

        sleep(1);
        $profiler->finish('select from something', [1 => 2]);

        $logger  = $profiler->getLogger();
        $message = $logger->getMessages()[0];

        $I->assertNotFalse(strpos($message, 'my-method (1.'));
        $I->assertNotFalse(strpos($message, 'select from something #0'));
    }
}
