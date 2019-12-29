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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;

class IsVisibleModelPropertyCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: isVisibleModelProperty()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-08-12
     *
     * @dataProvider publicPropertiesProvider
     */
    public function mvcModelManagerIsVisibleModelProperty(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Manager - isVisibleModelProperty()');

        $manager = $this->getService('modelsManager');

        $property = $example[0];
        $expected = $example[1];

        $actual = $manager->isVisibleModelProperty(
            new Customers(),
            $property
        );

        $I->assertEquals($expected, $actual);
    }

    protected function publicPropertiesProvider(): array
    {
        return [
            ['id', true],
            ['document_id', true],
            ['customer_id', true],
            ['first_name', true],
            ['some_field', false],
            ['', false],
            ['protected_field', false],
            ['private_field', false],
        ];
    }
}
