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

namespace Phalcon\Tests\Unit\Forms;

use Error;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exceptions\InvalidEntity;
use Phalcon\Forms\Exceptions\InvalidFilterType;
use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Forms\Manager;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use TypeError;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/851
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: mixed, 1: array{0: mixed, 1: mixed}}>
     */
    public static function getClearFields(): array
    {
        return [
            'null' => [null, ['d', 'five']],
            'int'  => [5, ['x', 'five']],
        ];
    }

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getInvalidFilters(): array
    {
        return [
            'null'   => [null],
            'int'    => [5],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getOptions(): array
    {
        return [
            'null' => [null],
            'int'  => [5],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getOptions')]
    public function testFormsElementSelectSetOptions(mixed $options): void
    {
        $select = new Select('s');
        $select->setOptions($options);

        $this->assertSame($options, $select->getOptions());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getInvalidFilters')]
    public function testFormsElementSetFilters(mixed $filters): void
    {
        $this->expectException(InvalidFilterType::class);
        $this->expectExceptionMessage('The filter needs to be an array or string');

        (new Text('name'))->setFilters($filters);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testFormsFormBindEntity(): void
    {
        $form = new Form();
        $form->add(new Text('name'));

        $form->bind(['name' => 'x'], null);
        $this->assertSame('x', $form->getValue('name'));

        $this->expectException(Error::class);
        $this->expectExceptionMessage('Attempt to assign property "name" on int');

        $form->bind(['name' => 'x'], 5);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param array{0: mixed, 1: mixed} $expected
     */
    #[DataProvider('getClearFields')]
    public function testFormsFormClear(mixed $fields, array $expected): void
    {
        $form = $this->getClearForm();
        $form->clear($fields);

        $this->assertSame($expected, [$form->getValue('name'), $form->getValue('5')]);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testFormsFormClearObject(): void
    {
        $this->expectException(TypeError::class);

        $this->getClearForm()->clear(new stdClass());
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testFormsManagerCreateAndLoadForm(): void
    {
        $manager = new Manager(new FormsLocator());

        $this->assertNull($manager->create('f', null)->getEntity());
        $this->assertNull($manager->loadForm('g', new ArrayLoader([]), null)->getEntity());

        $this->expectException(InvalidEntity::class);
        $this->expectExceptionMessage('The base entity is not valid');

        $manager->loadForm('h', new ArrayLoader([]), 5);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testFormsManagerCreateInt(): void
    {
        $this->expectException(InvalidEntity::class);
        $this->expectExceptionMessage('The base entity is not valid');

        (new Manager(new FormsLocator()))->create('f', 5);
    }

    /**
     * A subclass that overrides getFilters() and getEntity() with no return
     * type loads, as in cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/851
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testFormsOverrideWithoutReturnType(): void
    {
        $element = new class ('name') extends Text {
            public function getFilters()
            {
                return ['trim'];
            }
        };

        $form = new class () extends Form {
            public function getEntity()
            {
                return 'entity';
            }
        };

        $this->assertSame(['trim'], $element->getFilters());
        $this->assertSame('entity', $form->getEntity());
    }

    private function getClearForm(): Form
    {
        $form = new Form();
        $form->add((new Text('name'))->setDefault('d'));
        $form->add((new Text('5'))->setDefault('five'));
        $form->bind(['name' => 'x', '5' => 'y'], null);

        return $form;
    }
}
