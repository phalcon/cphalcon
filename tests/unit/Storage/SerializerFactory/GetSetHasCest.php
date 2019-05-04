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

namespace Phalcon\Test\Unit\Storage\SerializerFactory;

use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Storage\Serializer\Rot13;
use UnitTester;

class GetSetHasCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerFactoryGetSetHas(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - get()/set()/has()');

        $mappers = ['rot13' => 'Phalcon\Test\Fixtures\Storage\Serializer\Rot13'];
        $service = new SerializerFactory($mappers);

        $actual = $service->has('unknown');
        $I->assertFalse($actual);

        $actual = $service->has('rot13');
        $I->assertTrue($actual);

        $actual = $service->has('php');
        $I->assertTrue($actual);

        $actual = $service->get('rot13');
        $class  = Rot13::class;
        $I->assertInstanceOf($class, $actual);
    }
}
