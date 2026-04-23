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
use Phalcon\Tests\Support\Traits\DiTrait;

final class BindTypesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelCriteriaBindTypes(): void
    {
        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria->bindTypes(
            [
                'one',
                'two',
            ]
        );

        $actual = $criteria->getParams();
        $this->assertArrayHasKey('bindTypes', $actual);

        $expected = [
            'one',
            'two',
        ];
        $actual   = $actual['bindTypes'];
        $this->assertEquals($expected, $actual);
    }
}
