<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Profiler\Profiler;

class IsSetActiveCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Profiler\Profiler ::
     * isActive()/setActive()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerIsSetActive(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Profiler\Profiler - isActive()/setActive()');

        $profiler = new Profiler();

        $I->assertFalse($profiler->isActive());

        $profiler->setActive(true);
        $I->assertTrue($profiler->isActive());
    }
}
