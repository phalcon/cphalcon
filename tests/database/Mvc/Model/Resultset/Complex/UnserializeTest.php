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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Complex;

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Traits\DiTrait;

final class UnserializeTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
            $this->setDiService('phpSerializer');
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-06
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetComplexUnserialize(): void
    {
        $complex = new Complex(null);

        $expected = [
            'cache'       => null,
            'rows'        => [],
            'columnTypes' => [['__FAKE__']],
            'hydrateMode' => 0,
        ];

        $this->assertTrue($this->container->has('serializer'));

        $complex->unserialize(serialize($expected));

        $this->assertEquals([['__FAKE__']], $this->getProtectedProperty($complex, 'columnTypes'));
        $this->assertEquals(0, $this->getProtectedProperty($complex, 'hydrateMode'));
    }
}
