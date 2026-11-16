<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Filter\Validation;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The validation writes the values to the entity with the PHP weak type
 * rules, the same as cphalcon. The test file declares strict_types=1, so the
 * mode of the caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * The entity has no setter, so bind() writes the property.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testFilterValidationWeakModeBindProperty(): void
    {
        $entity = new class {
            public ?int $age = null;
        };

        $validation = new Validation();
        $validation->setDI(new FactoryDefault());
        $validation->bind($entity, ['age' => '5']);

        $this->assertSame(5, $entity->age);
    }

    /**
     * The entity has a setter, so bind() calls it.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testFilterValidationWeakModeBindSetter(): void
    {
        $target = new IntTarget();

        $validation = new Validation();
        $validation->setDI(new FactoryDefault());
        $validation->bind($target, ['value' => '5']);

        $this->assertSame(5, $target->value);
    }

    /**
     * The trim sanitizer returns a string. getValue() writes it to the int
     * property of the entity.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testFilterValidationWeakModeGetValueWrite(): void
    {
        $entity = new class {
            public ?int $age = 5;
        };

        $validation = new Validation();
        $validation->setDI(new FactoryDefault());
        $validation->setFilters('age', 'trim');
        $validation->setEntity($entity);

        $validation->getValue('age');

        $this->assertSame(5, $entity->age);
    }
}
