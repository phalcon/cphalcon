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

use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

trait TranslateCsvHelperTrait
{
    protected string $function = '_';

    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    public static function getQueryOneVariable(): array
    {

        return [['en',
            ['hello-key' => 'Hello my friend',],],
            ['es',
                ['hello-key' => 'Hola my friend',],],
            ['fr',
                ['hello-key' => 'Bonjour my friend',],],];
    }

    /**
     * Data provider for the query tests
     *
     * @return array[]
     */
    public static function getQueryProvider(): array
    {

        return [['en',
            ['hi' => 'Hello',
                'bye' => 'Good Bye',],],
            ['es',
                ['hi' => 'Hola',
                    'bye' => 'Adiós',],],
            ['fr',
                ['hi' => 'Bonjour',
                    'bye' => 'Au revoir',],],];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array[]
     */
    public static function getQueryTwoVariables(): array
    {

        return [
            [
                'en',
                ['song-key' => 'This song is Dust in the wind (Kansas)',],
            ],
            [
                'es',
                ['song-key' => 'La canción es Dust in the wind (Kansas)',],
            ],
            [
                'fr',
                ['song-key' => 'La chanson est Dust in the wind (Kansas)',],
            ],
        ];
    }

    /**
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterCsvQuery(string $code, array $tests): void
    {

        $language = $this->getCsvConfig()[$code];
        $translator = new Csv(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->function}($key);

            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @return array
     */
    abstract protected function getCsvConfig(): array;

    /**
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterCsvVariableSubstitutionNoVariables(string $code, array $tests): void
    {

        $language = $this->getCsvConfig()[$code];
        $translator = new Csv(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->function}($key, ['name' => 'my friend',]);

            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getQueryOneVariable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterCsvVariableSubstitutionOneVariable(string $code, array $tests): void
    {

        $language = $this->getCsvConfig()[$code];
        $translator = new Csv(new InterpolatorFactory(), $language);

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->function}($key, ['name' => 'my friend']);
            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @dataProvider getQueryTwoVariables
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testTranslateAdapterCsvVariableSubstitutionTwoVariable(string $code, array $tests): void
    {

        $language = $this->getCsvConfig()[$code];
        $translator = new Csv(new InterpolatorFactory(), $language);
        $vars = ['song' => 'Dust in the wind',
            'artist' => 'Kansas',];

        foreach ($tests as $key => $expected) {
            $actual = $translator->{$this->function}($key, $vars);

            $this->assertSame($expected, $actual);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterCsvWithArrayAccessAndUTF8Strings(): void
    {

        $language = $this->getCsvConfig()['ru'];
        $translator = new Csv(new InterpolatorFactory(), $language);

        $vars = ['fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',];
        $expected = 'Привет, John D. Doe!';
        $actual = $translator->{$this->function}('Hello %fname% %mname% %lname%!', $vars);
        $this->assertSame($expected, $actual);
    }

    /**
     * @return string
     */
    abstract protected function func(): string;
}
