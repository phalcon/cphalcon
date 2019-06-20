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

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;
use function sprintf;

class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: path()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterGroupedPathDefault(UnitTester $I)
    {
        $this->checkPathDefault($I, 'Grouped');
    }
}
