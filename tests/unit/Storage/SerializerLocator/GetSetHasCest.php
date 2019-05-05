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

namespace Phalcon\Test\Unit\Storage\SerializerLocator;

use Closure;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\SerializerLocator;
use UnitTester;

class GetSetHasCest
{
    /**
     * Tests Phalcon\Storage\SerializerLocator :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerLocatorGet(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerLocator - get()');

        $locator = new SerializerLocator();

        $locator->set(
            'php',
            function () {
                return new Php();
            }
        );

        $actual = $locator->has('unknown');
        $I->assertFalse($actual);

        $actual = $locator->has('php');
        $I->assertTrue($actual);

        $actual = $locator->get('php');
        $class  = Php::class;
        $I->assertInstanceOf($class, $actual);
    }
}
