<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Helpers;

use Codeception\Example;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use UnitTester;

class TranslateQueryHelper
{
    use TranslateTrait;

    protected $function = '_';

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query()
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @dataProvider getQueryProvider
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayQuery(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - %s - %s',
                $this->function,
                $data['language']
            )
        );
        $language   = $this->getArrayConfig()[$data['code']];
        $translator = new NativeArray(['content' => $language]);
        foreach ($data['tests'] as $key => $expected) {
            $actual   = $translator->{$this->function}($key);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string with no variables
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @dataProvider getQueryProvider
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function translateAdapterNativearrayVariableSubstitutionNoVariables(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - variable substitution no variables - %s',
                $data['language']
            )
        );
        $language   = $this->getArrayConfig()[$data['code']];
        $translator = new NativeArray(['content' => $language]);
        foreach ($data['tests'] as $key => $expected) {
            $actual   = $translator->{$this->function}($key, ['name' => 'my friend']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (one variable)
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @dataProvider getQueryOneVariable
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function translateAdapterNativearrayVariableSubstitutionOneVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - variable substitution one variable - %s',
                $data['language']
            )
        );
        $language   = $this->getArrayConfig()[$data['code']];
        $translator = new NativeArray(['content' => $language]);
        foreach ($data['tests'] as $key => $expected) {
            $actual   = $translator->{$this->function}($key, ['name' => 'my friend']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() -
     * variable substitution in string (two variables)
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @dataProvider getQueryTwoVariables
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function translateAdapterNativearrayVariableSubstitutionTwoVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\NativeArray - variable substitution two variables - %s',
                $data['language']
            )
        );
        $language   = $this->getArrayConfig()[$data['code']];
        $translator = new NativeArray(['content' => $language]);
        $vars       = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];
        foreach ($data['tests'] as $key => $expected) {
            $actual   = $translator->{$this->function}($key, $vars);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: query() - array access and UTF8 strings
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-12
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language   = $this->getArrayConfig()['ru'];
        $translator = new NativeArray(['content' => $language]);

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $expected = 'Привет, John D. Doe!';
        $actual   = $translator->{$this->function}('Hello %fname% %mname% %lname%!', $vars);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Data provider for the query tests
     *
     * @return array
     */
    private function getQueryProvider(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hi'  => 'Hello',
                    'bye' => 'Good Bye',
                ],
            ],
            [
                'language' => 'Spanish',
                'code'     => 'es',
                'tests'    => [
                    'hi'  => 'Hola',
                    'bye' => 'Adiós',
                ],
            ],
            [
                'language' => 'French',
                'code'     => 'fr',
                'tests'    => [
                    'hi'  => 'Bonjour',
                    'bye' => 'Au revoir',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array
     */
    private function getQueryOneVariable(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hello-key' => 'Hello my friend',
                ],
            ],
            [
                'language' => 'Spanish',
                'code'     => 'es',
                'tests'    => [
                    'hello-key' => 'Hola my friend',
                ],
            ],
            [
                'language' => 'French',
                'code'     => 'fr',
                'tests'    => [
                    'hello-key' => 'Bonjour my friend',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     *
     * @return array
     */
    private function getQueryTwoVariables(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'song-key' => 'This song is Dust in the wind (Kansas)',
                ],
            ],
            [
                'language' => 'Spanish',
                'code'     => 'es',
                'tests'    => [
                    'song-key' => 'La canción es Dust in the wind (Kansas)',
                ],
            ],
            [
                'language' => 'French',
                'code'     => 'fr',
                'tests'    => [
                    'song-key' => 'La chanson est Dust in the wind (Kansas)',
                ],
            ],
        ];
    }
}
