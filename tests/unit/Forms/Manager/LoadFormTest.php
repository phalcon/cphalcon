<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Manager;

use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Forms\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class LoadFormTest extends AbstractUnitTestCase
{
    private Manager $manager;

    protected function setUp(): void
    {
        parent::setUp();
        $this->manager = new Manager(new FormsLocator());
    }
    // -----------------------------------------------------------------------
    // Registration
    // -----------------------------------------------------------------------

    public function testLoadFormRegistersFormByName(): void
    {

        $schema  = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $this->manager->loadForm('login', $schema);

        $this->assertTrue($this->manager->has('login'));
    }

    public function testLoadFormReturnsForm(): void
    {

        $schema  = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $form = $this->manager->loadForm('login', $schema);

        $this->assertInstanceOf(Form::class, $form);
    }

    public function testLoadFormReturnedFormMatchesStoredForm(): void
    {

        $schema  = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $returned = $this->manager->loadForm('login', $schema);
        $stored   = $this->manager->get('login');

        $this->assertSame($returned, $stored);
    }

    // -----------------------------------------------------------------------
    // Elements are added
    // -----------------------------------------------------------------------

    public function testLoadFormAddsElements(): void
    {

        $schema  = new ArrayLoader([
            ['type' => 'text',     'name' => 'username'],
            ['type' => 'email',    'name' => 'email'],
            ['type' => 'password', 'name' => 'password'],
        ]);

        $form = $this->manager->loadForm('register', $schema);

        $this->assertCount(3, $form->getElements());
        $this->assertInstanceOf(Text::class,     $form->get('username'));
        $this->assertInstanceOf(Email::class,    $form->get('email'));
        $this->assertInstanceOf(Password::class, $form->get('password'));
    }

    // -----------------------------------------------------------------------
    // Entity
    // -----------------------------------------------------------------------

    public function testLoadFormWithNullEntity(): void
    {

        $schema  = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $form = $this->manager->loadForm('login', $schema, null);

        $this->assertNull($form->getEntity());
    }

    public function testLoadFormPassesEntityToForm(): void
    {

        $entity  = new stdClass();
        $schema  = new ArrayLoader([
            ['type' => 'text', 'name' => 'username'],
        ]);

        $form = $this->manager->loadForm('login', $schema, $entity);

        $this->assertSame($entity, $form->getEntity());
    }

    // -----------------------------------------------------------------------
    // Overwrite
    // -----------------------------------------------------------------------

    public function testLoadFormOverwritesPreviousForm(): void
    {


        $this->manager->loadForm('profile', new ArrayLoader([
            ['type' => 'text', 'name' => 'first_name'],
        ]));

        $this->manager->loadForm('profile', new ArrayLoader([
            ['type' => 'email', 'name' => 'contact_email'],
        ]));

        $stored = $this->manager->get('profile');
        $this->assertFalse($stored->has('first_name'));
        $this->assertTrue($stored->has('contact_email'));
    }

    // -----------------------------------------------------------------------
    // Empty schema
    // -----------------------------------------------------------------------

    public function testLoadFormWithEmptySchema(): void
    {

        $schema  = new ArrayLoader([]);

        $form = $this->manager->loadForm('empty', $schema);

        $this->assertTrue($this->manager->has('empty'));
        $this->assertCount(0, $form->getElements());
    }
}
