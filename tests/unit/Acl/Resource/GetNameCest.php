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

namespace Phalcon\Test\Unit\Acl\Resource;

use Phalcon\Acl\Resource;
use UnitTester;

/**
 * Class GetNameCest
 *
 * @package Phalcon\Test\Unit\Acl\Resource
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Acl\Resource :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclResourceGetName(UnitTester $I)
    {
        $I->wantToTest('Acl\Resource - getName()');
        $resource = new Resource('Customers');

        $expected = 'Customers';
        $actual   = $resource->getName();
        $I->assertEquals($expected, $actual);
    }
}
