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
use Phalcon\Tests\Models\EntityWithGetter;
use Phalcon\Tests\Models\EntityWithHook;
use Phalcon\Tests\Models\EntityWithPublic;
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
     * @since  2021-11-07
     */
    public function validationGetValueByEntityPublic(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getValueByEntity() - public property');

        $entity = new EntityWithPublic(self::NAME);

        $validation = new Validation();
        $value = $validation->getValueByEntity($entity, 'name');

        $I->assertSame($entity->name, $value);
    }

    public function validationGetValueByEntityGetter(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getValueByEntity() - getter');

        $entity = new EntityWithGetter(self::NAME);

        $validation = new Validation();
        $value = $validation->getValueByEntity($entity, 'name');

        $I->assertSame($entity->getName(), $value);
    }

    public function validationGetValueByEntityReadAttribute(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getValueByEntity() - readAttribute');

        $entity = new EntityWithHook(self::NAME);

        $validation = new Validation();
        $value = $validation->getValueByEntity($entity, 'name');

        $I->assertSame($entity->readAttribute('name'), $value);
    }
}
