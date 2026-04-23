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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Tests\Support\Models\EntityWithGetter;
use Phalcon\Tests\Support\Models\EntityWithHook;
use Phalcon\Tests\Support\Models\EntityWithPublic;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetValueByEntityTest extends AbstractUnitTestCase
{
    public const NAME = 'John Doe';

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationGetValueByEntityGetter(): void
    {
        $entity = new EntityWithGetter(self::NAME);

        $validation = new Validation();
        $value      = $validation->getValueByEntity($entity, 'name');

        $expected = $entity->getName();
        $actual   = $value;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationGetValueByEntityPublic(): void
    {
        $entity = new EntityWithPublic(self::NAME);

        $validation = new Validation();
        $value      = $validation->getValueByEntity($entity, 'name');

        $expected = $entity->name;
        $actual   = $value;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationGetValueByEntityReadAttribute(): void
    {
        $entity = new EntityWithHook(self::NAME);

        $validation = new Validation();
        $value      = $validation->getValueByEntity($entity, 'name');

        $expected = $entity->readAttribute('name');
        $actual   = $value;
        $this->assertSame($expected, $actual);
    }
}
