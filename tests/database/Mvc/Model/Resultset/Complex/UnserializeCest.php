<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model\Resultset\Complex;

use DatabaseTester;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;

class UnserializeCest
{
    use DiTrait;
    use RecordsTrait;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
            $this->setDiService('phpSerializer');
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Complex :: unserialize()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     *
     * @group  common
     */
    public function mvcModelResultsetComplexUnserialize(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Complex - unserialize()');

        $complex = new Complex(null);

        $expected = [
            'cache'       => null,
            'rows'        => [],
            'columnTypes' => [ ['__COMPLEX__'] ],
            'hydrateMode' => '__COMPLEX__'
        ];

        $I->assertTrue($this->container->has('serializer'));

        $complex->unserialize(serialize($expected));

        $I->assertEquals([ ['__COMPLEX__'] ], $I->getProtectedProperty($complex, 'columnTypes'));
        $I->assertEquals('__COMPLEX__', $I->getProtectedProperty($complex, 'hydrateMode'));
    }
}
