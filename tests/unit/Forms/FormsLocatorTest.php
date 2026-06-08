<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms;

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Forms\FormsLocator;
use Phalcon\Forms\Loader\ArrayLoader;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FakeCountingFormFactory;
use Phalcon\Tests\Unit\Forms\Fake\FakeLoginFormFactory;
use Phalcon\Tests\Unit\Forms\Fake\FakeRegisterFormFactory;
use Phalcon\Tests\Unit\Forms\Fake\FakeSentinelElementFactory;
use Phalcon\Tests\Unit\Forms\Fake\FakeTextElementFactory;
use Phalcon\Tests\Unit\Forms\Fake\FakeUsernameFormFactory;
use stdClass;

final class FormsLocatorTest extends AbstractUnitTestCase
{
    // -----------------------------------------------------------------------
    // Constructor
    // -----------------------------------------------------------------------

    public function testConstructorAcceptsDefinitionMap(): void
    {
        $locator = new FormsLocator([
            'login' => new FakeLoginFormFactory(),
        ]);

        $this->assertTrue($locator->has('login'));
    }

    public function testEmptyConstructorProducesEmptyLocator(): void
    {
        $locator = new FormsLocator();

        $this->assertFalse($locator->has('login'));
    }

    // -----------------------------------------------------------------------
    // has()
    // -----------------------------------------------------------------------

    public function testHasReturnsFalseForUnregisteredName(): void
    {
        $locator = new FormsLocator();

        $this->assertFalse($locator->has('unknown'));
    }

    public function testHasReturnsTrueAfterSet(): void
    {
        $locator = new FormsLocator();
        $locator->set('login', new FakeLoginFormFactory());

        $this->assertTrue($locator->has('login'));
    }

    // -----------------------------------------------------------------------
    // get() - no entity (cached)
    // -----------------------------------------------------------------------

    public function testGetReturnsFormInstance(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);

        $form = $locator->get('login');

        $this->assertInstanceOf(Form::class, $form);
    }

    public function testGetWithoutEntityReturnsSameInstance(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);

        $form1 = $locator->get('login');
        $form2 = $locator->get('login');

        $this->assertSame($form1, $form2);
    }

    public function testGetThrowsForUnregisteredName(): void
    {
        $locator = new FormsLocator();

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches("/not registered/i");

        $locator->get('unknown');
    }

    // -----------------------------------------------------------------------
    // get() - with entity (never cached)
    // -----------------------------------------------------------------------

    public function testGetWithEntityReturnsFreshFormEachTime(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);
        $entity  = new stdClass();

        $form1 = $locator->get('login', $entity);
        $form2 = $locator->get('login', $entity);

        $this->assertNotSame($form1, $form2);
    }

    public function testGetWithEntityBindsEntityToForm(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);
        $entity  = new stdClass();

        $form = $locator->get('login', $entity);

        $this->assertSame($entity, $form->getEntity());
    }

    public function testGetWithEntityDoesNotShareWithNoEntityCache(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);
        $entity  = new stdClass();

        $cached = $locator->get('login');
        $fresh  = $locator->get('login', $entity);

        $this->assertNotSame($cached, $fresh);
    }

    // -----------------------------------------------------------------------
    // set()
    // -----------------------------------------------------------------------

    public function testSetRegistersNewFactory(): void
    {
        $locator = new FormsLocator();
        $locator->set('contact', new FakeLoginFormFactory());

        $this->assertTrue($locator->has('contact'));
        $this->assertInstanceOf(Form::class, $locator->get('contact'));
    }

    public function testSetReplacesExistingFactoryAndClearsCache(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);

        $original = $locator->get('login');

        $locator->set('login', new FakeUsernameFormFactory());

        $replaced = $locator->get('login');

        $this->assertNotSame($original, $replaced);
        $this->assertTrue($replaced->has('username'));
        $this->assertFalse($replaced->has('email'));
    }

    public function testSetClearsCachedInstanceOnReplacement(): void
    {
        $locator = new FormsLocator(['login' => new FakeLoginFormFactory()]);

        // Prime the cache
        $locator->get('login');

        $factory = new FakeCountingFormFactory();
        $locator->set('login', $factory);

        $locator->get('login');

        $this->assertSame(1, $factory->callCount);
    }

    // -----------------------------------------------------------------------
    // Multiple forms
    // -----------------------------------------------------------------------

    public function testMultipleFormsAreIndependent(): void
    {
        $locator = new FormsLocator([
            'login'    => new FakeLoginFormFactory(),
            'register' => new FakeRegisterFormFactory(),
        ]);

        $login    = $locator->get('login');
        $register = $locator->get('register');

        $this->assertSame(2, $login->count());
        $this->assertSame(2, $register->count());
        $this->assertNotSame($login, $register);
        $this->assertTrue($login->has('password'));
        $this->assertTrue($register->has('username'));
        $this->assertFalse($login->has('username'));
        $this->assertFalse($register->has('password'));
    }

    // -----------------------------------------------------------------------
    // Element registry
    // -----------------------------------------------------------------------

    /**
     * @return array<string, array<int, string>>
     */
    public static function getBuiltInTypes(): array
    {
        return [
            'check'      => ['check'],
            'checkgroup' => ['checkgroup'],
            'date'       => ['date'],
            'email'      => ['email'],
            'file'       => ['file'],
            'hidden'     => ['hidden'],
            'numeric'    => ['numeric'],
            'password'   => ['password'],
            'radio'      => ['radio'],
            'radiogroup' => ['radiogroup'],
            'select'     => ['select'],
            'submit'     => ['submit'],
            'text'       => ['text'],
            'textarea'   => ['textarea'],
        ];
    }

    /**
     * @dataProvider getBuiltInTypes
     */
    public function testHasElementReturnsTrueForBuiltInType(string $type): void
    {
        $locator = new FormsLocator();

        $this->assertTrue($locator->hasElement($type));
    }

    public function testHasElementReturnsFalseForUnknownType(): void
    {
        $locator = new FormsLocator();

        $this->assertFalse($locator->hasElement('mytype'));
    }

    public function testGetElementReturnsCallableForBuiltInType(): void
    {
        $locator  = new FormsLocator();
        $factory  = $locator->getElement('text');

        $this->assertIsCallable($factory);
    }

    public function testGetElementThrowsForUnknownType(): void
    {
        $locator = new FormsLocator();

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Unknown form element type/i');

        $locator->getElement('unknowntype');
    }

    public function testSetElementRegistersCustomType(): void
    {
        $locator = new FormsLocator();
        $locator->setElement('mytype', new FakeTextElementFactory());

        $this->assertTrue($locator->hasElement('mytype'));
    }

    public function testSetElementOverridesBuiltInType(): void
    {
        $locator  = new FormsLocator();
        $sentinel = new Text('replaced');

        $locator->setElement('email', new FakeSentinelElementFactory($sentinel));

        $factory = $locator->getElement('email');
        $result  = $factory('email', [], []);

        $this->assertSame($sentinel, $result);
    }

    public function testFormLoadUsesLocatorElementType(): void
    {
        $locator  = new FormsLocator();
        $sentinel = new Text('myfield');

        $locator->setElement('mytype', new FakeSentinelElementFactory($sentinel));

        $form = (new Form())->load(new ArrayLoader([
            ['type' => 'mytype', 'name' => 'myfield'],
        ]), $locator);

        $this->assertTrue($form->has('myfield'));
        $this->assertSame($sentinel, $form->get('myfield'));
    }
}
