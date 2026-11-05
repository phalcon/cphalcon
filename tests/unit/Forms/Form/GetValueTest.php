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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FakeFormCustomValue;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * Class GetValueTest extends AbstractUnitTestCase
 */
final class GetValueTest extends AbstractUnitTestCase
{
    /**
     * @return array<int, array<int, string>>
     */
    public static function getTagFactoryNames(): array
    {
        return [
            ['tagFactory'],
            ['tagfactory'],
            ['TAGFACTORY'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormGetValueCustomValueMethod(): void
    {
        $form = new FakeFormCustomValue();
        $form->add(new Text('username'));

        $actual = $form->getValue('username');
        $this->assertSame('custom-username', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormGetValueForbiddenNameReturnsNull(): void
    {
        $form = new Form();
        $form->add(new Text('action'));

        $actual = $form->getValue('action');
        $this->assertNull($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17727
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-04
     */
    #[DataProvider('getTagFactoryNames')]
    public function testFormsFormGetValueForbiddenTagFactoryReturnsNull(string $name): void
    {
        $form = new Form();
        $form->setTagFactory(new TagFactory(new Escaper()));

        $actual = $form->getValue($name);
        $this->assertNull($actual);
    }
}
