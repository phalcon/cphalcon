<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Helpers;

use Codeception\Example;
use Phalcon\Test\Fixtures\Traits\TranslateCsvTrait;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class TranslateCsvHelper
{
    use TranslateCsvTrait;

    protected $function = '_';

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query()
     *
     * @dataProvider getQueryProvider
     *
     * @author       Ivan Zubok <chi_no@ukr.net>
     * @since        2014-11-04
     */
    public function translateAdapterCsvQuery(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - %s - %s',
                $this->function,
                $data['language']
            )
        );

        $language = $this->getCsvConfig()[$data['code']];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}($key)
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() -
     * variable substitution in string with no variables
     *
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterCsvVariableSubstitutionNoVariables(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution no variables - %s',
                $data['language']
            )
        );

        $language = $this->getCsvConfig()[$data['code']];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}(
                    $key,
                    [
                        'name' => 'my friend',
                    ]
                )
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() -
     * variable substitution in string (one variable)
     *
     * @dataProvider getQueryOneVariable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterCsvVariableSubstitutionOneVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution one variable - %s',
                $data['language']
            )
        );

        $language = $this->getCsvConfig()[$data['code']];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->function}($key, ['name' => 'my friend']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() -
     * variable substitution in string (two variables)
     *
     * @dataProvider getQueryTwoVariables
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterCsvVariableSubstitutionTwoVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution two variables - %s',
                $data['language']
            )
        );

        $language = $this->getCsvConfig()[$data['code']];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}($key, $vars)
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() - array access and UTF8
     * strings
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language = $this->getCsvConfig()['ru'];

        $translator = new Csv(
            new InterpolatorFactory(),
            $language
        );

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $I->assertEquals(
            'Привет, John D. Doe!',
            $translator->{$this->function}('Hello %fname% %mname% %lname%!', $vars)
        );
    }

    /**
     * Data provider for the query tests
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
