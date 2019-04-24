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

namespace Phalcon\Test\Unit\Cache\Adapter\Apcu;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

/**
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - getPrefix()');
        $adapter = new Apcu(['prefix' => 'my-prefix']);

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: getPrefix() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - getPrefix() - default');
        $adapter = new Apcu();

        $expected = 'ph-memc-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
