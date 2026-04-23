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

namespace Phalcon\Tests\Unit\Translate\Fake;

use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

trait TranslateGettextHelperTrait
{
    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    public static function getQueryOneVariable(): array
    {

        return [[['hello-key' => 'Hello my friend',],],];
    }

    /**
     * Data provider for the query tests
     *
     * @return array[]
     */
    public static function getQueryProvider(): array
    {

        return [[['hi' => 'Hello',
            'bye' => 'Bye',],],];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    public static function getQueryTwoVariables(): array
    {

        return [[['song-key' => 'The song is Dust in the wind (Kansas)',],],];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextWithArrayAccessAndUTF8Strings()
    {

        $language = $this->getGettextConfig();

        $translator = new Gettext(new InterpolatorFactory(), $language);

        $vars = ['fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',];

        $expected = 'Привет, John D. Doe!';
        $actual = $translator->{$this->func()}('Привет, %fname% %mname% %lname%!', $vars);
        $this->assertSame($expected, $actual);
    }

    /**
     * @return array
     */
    abstract protected function getGettextConfig(): array;

    /**
     * @return string
     */
    abstract protected function func(): string;

    /**
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterGettextQuery(array $tests): void
    {

        $language = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->func()}($key);
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterGettextVariableSubstitutionNoVariables(array $tests): void
    {

        $language = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->func()}($key, ['name' => 'my friend',]);
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getQueryOneVariable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterGettextVariableSubstitutionOneVariable(array $tests): void
    {

        $language = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->func()}($key, ['name' => 'my friend']);
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getQueryTwoVariables
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterGettextVariableSubstitutionTwoVariable(array $tests): void
    {

        $language = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $language);

        $vars = ['song' => 'Dust in the wind',
            'artist' => 'Kansas',];

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->func()}($key, $vars);
            $this->assertSame($expected, $actual);
        }
    }
}
