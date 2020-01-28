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

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterGroupedPath(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Grouped - path()');

        $config = $this->getConfig('Grouped');

        $I->assertCount(
            2,
            $config->path('test')
        );


        $I->assertEquals(
            'something-else',
            $config->path('test.property2')
        );
    }

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: path() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterGroupedPathDefault(UnitTester $I)
    {
        $this->checkPathDefault($I, 'Grouped');
    }
}
