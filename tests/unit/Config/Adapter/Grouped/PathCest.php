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

namespace Phalcon\Tests\Unit\Config\Adapter\Grouped;

use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
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

        $expected = 2;
        $actual   = $config->path('test');
        $I->assertCount($expected, $actual);


        $expected = 'something-else';
        $actual   = $config->path('test.property2');
        $I->assertEquals($expected, $actual);
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
