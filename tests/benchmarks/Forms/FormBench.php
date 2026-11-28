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

namespace Phalcon\Tests\Benchmarks\Forms;

use Phalcon\Di\Di;
use Phalcon\Filter\Validation\Validator\Email as EmailValidator;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

#[BeforeMethods('setUp')]
#[Revs(200)]
final class FormBench
{
    private const ELEMENTS = ['name', 'email', 'password', 'country', 'about'];

    private const EXPECTED_HTML = '<input type="text" id="name" name="name">'
        . '<input type="email" id="email" name="email">'
        . '<input type="password" id="password" name="password">'
        . '<select id="country" name="country">' . PHP_EOL
        . "\t" . '<option value="de">Germany</option>' . PHP_EOL
        . "\t" . '<option value="gr">Greece</option>' . PHP_EOL
        . "\t" . '<option value="us">USA</option>' . PHP_EOL
        . '</select>'
        . '<textarea id="about" name="about"></textarea>';

    private const VALID_DATA = [
        'about'    => 'A full stack PHP framework',
        'country'  => 'gr',
        'email'    => 'team@phalcon.io',
        'name'     => 'Phalcon',
        'password' => 'secret123',
    ];

    private Form $form;

    private TagFactory $tagFactory;

    /**
     * Select::render() uses Phalcon\Tag, which reads the 'escaper' service
     * of the default container. The container has only this service.
     */
    public function setUp(): void
    {
        Di::reset();

        $container = new Di();
        $container->setShared('escaper', Escaper::class);
        Di::setDefault($container);

        $this->tagFactory = new TagFactory(new Escaper());
        $this->form       = $this->buildForm();
    }

    /**
     * A form with 5 elements and their validators, as one request makes it.
     */
    public function benchConstruct(): void
    {
        $form = $this->buildForm();

        if (5 !== $form->count()) {
            throw new RuntimeException(sprintf('Unexpected count: %d', $form->count()));
        }
    }

    public function benchIsValid(): void
    {
        if (true !== $this->form->isValid(self::VALID_DATA)) {
            throw new RuntimeException('Unexpected value: false');
        }
    }

    public function benchRender(): void
    {
        $actual = '';
        foreach (self::ELEMENTS as $name) {
            $actual .= $this->form->render($name);
        }

        if (self::EXPECTED_HTML !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $actual));
        }
    }

    private function buildForm(): Form
    {
        $name = new Text('name');
        $name->addValidators(
            [
                new PresenceOf(),
                new StringLength(['max' => 50, 'min' => 2]),
            ]
        );

        $email = new Email('email');
        $email->addValidators(
            [
                new PresenceOf(),
                new EmailValidator(),
            ]
        );

        $password = new Password('password');
        $password->addValidator(new StringLength(['min' => 8]));

        $country = new Select(
            'country',
            [
                'de' => 'Germany',
                'gr' => 'Greece',
                'us' => 'USA',
            ]
        );

        $form = new Form();
        $form->setTagFactory($this->tagFactory);
        $form->add($name);
        $form->add($email);
        $form->add($password);
        $form->add($country);
        $form->add(new TextArea('about'));

        return $form;
    }
}
