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

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;
use Phalcon\Validation;

/**
 * Class GetValueByEntityCest
 */
class GetValueByEntityCest
{
    public const NAME = 'John Doe';

    /**
     * Tests Phalcon\Validation :: getValueByEntity()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function validationGetValueByEntityPublic(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValueByEntity()');

        $user = new class() {
            public $name = GetValueByEntityCest::NAME;
        };

        $validation = new Validation();
        $value = $validation->getValueByEntity($user, 'name');

        $I->assertSame($user->name, $value);
    }

    public function validationGetValueByEntityGetter(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValueByEntity()');

        $user = new class() {
            private $name = GetValueByEntityCest::NAME;

            public function getName()
            {
                return $this->name;
            }
        };

        $validation = new Validation();
        $value = $validation->getValueByEntity($user, 'name');

        $I->assertSame($user->getName(), $value);
    }

    public function validationGetValueByEntityReadAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValueByEntity()');

        $user = new class() {
            private $name = GetValueByEntityCest::NAME;

            public function readAttribute(string $field)
            {
                return $this->{$field};
            }
        };

        $validation = new Validation();
        $value = $validation->getValueByEntity($user, 'name');

        $I->assertSame($user->readAttribute('name'), $value);
    }
}
