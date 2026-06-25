<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Manager;

use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Forms\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class LocatorTest extends AbstractUnitTestCase
{
    public function testLoadFormLocatorCachesFormWithoutEntity(): void
    {
        $locator = new FormsLocator();
        $manager = new Manager($locator);

        $manager->loadForm('login', $this->schema());

        $form1 = $locator->get('login');
        $form2 = $locator->get('login');

        $this->assertSame($form1, $form2);
    }

    public function testLoadFormLocatorCanProduceFreshFormWithEntity(): void
    {
        $locator = new FormsLocator();
        $manager = new Manager($locator);
        $entity  = new stdClass();

        $manager->loadForm('login', $this->schema());

        $form = $locator->get('login', $entity);

        $this->assertInstanceOf(Form::class, $form);
        $this->assertSame($entity, $form->getEntity());
    }

    // -----------------------------------------------------------------------
    // loadForm() with locator
    // -----------------------------------------------------------------------

    public function testLoadFormRegistersInBothManagerAndLocator(): void
    {
        $locator = new FormsLocator();
        $manager = new Manager($locator);

        $manager->loadForm('login', $this->schema());

        $this->assertTrue($manager->has('login'));
        $this->assertTrue($locator->has('login'));
    }

    // -----------------------------------------------------------------------
    // Constructor / getLocator
    // -----------------------------------------------------------------------

    public function testManagerReturnsLocator(): void
    {
        $locator = new FormsLocator();
        $manager = new Manager($locator);

        $this->assertSame($locator, $manager->getLocator());
    }

    // -----------------------------------------------------------------------
    // Standalone locator (no Manager involved)
    // -----------------------------------------------------------------------

    public function testStandaloneLocatorWorksWithoutManager(): void
    {
        $schema  = $this->schema();
        $locator = new FormsLocator([
            'login' => fn(?object $e) => (new Form($e))->load($schema, new FormsLocator()),
        ]);

        $this->assertTrue($locator->has('login'));
        $this->assertInstanceOf(Form::class, $locator->get('login'));
    }
    private function schema(): ArrayLoader
    {
        return new ArrayLoader([
            ['type' => 'email',    'name' => 'email'],
            ['type' => 'password', 'name' => 'password'],
        ]);
    }
}
