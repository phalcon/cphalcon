<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DM\Pdo\Profiler\Profiler;

use DatabaseTester;
use Phalcon\DM\Pdo\Profiler\Profiler;

class IsSetActiveCest
{
    /**
     * Database Tests Phalcon\DM\Pdo\Profiler\Profiler ::
     * isActive()/setActive()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerIsSetActive(DatabaseTester $I)
    {
        $I->wantToTest('DM\Pdo\Profiler\Profiler - isActive()/setActive()');

        $profiler = new Profiler();

        $I->assertFalse($profiler->isActive());

        $profiler->setActive(true);
        $I->assertTrue($profiler->isActive());
    }
}
