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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use Phalcon\Mvc\Model\Criteria;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class SharedLockTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelCriteriaSharedLock(): void
    {
        $criteria = new Criteria();

        $expected = [];
        $actual   = $criteria->getParams();
        $this->assertEquals($expected, $actual);

        $criteria->sharedLock(true);

        $expected = [
            'shared_lock' => true,
        ];
        $actual   = $criteria->getParams();
        $this->assertEquals($expected, $actual);
    }
}
