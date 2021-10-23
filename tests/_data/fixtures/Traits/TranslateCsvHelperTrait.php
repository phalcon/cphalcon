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

namespace Phalcon\Tests\Fixtures\Traits;

use Codeception\Example;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

use function sprintf;

/**
 * Trait TranslateCsvHelperTrait
 *
 * @package Phalcon\Tests\Fixtures\Traits
 */
trait TranslateCsvHelperTrait
{
    protected string $function = '_';

    /**
     * @return string
     */
    abstract protected function func(): string;

    /**
     * @return array
     */
    abstract protected function getCsvConfig(): array;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query()
     *
     * @dataProvider getQueryProvider
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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

        $language   = $this->getCsvConfig()[$data['code']];
        $translator = new Csv(new InterpolatorFactory(), $language);

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->function}($key);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() -
     * variable substitution in string with no variables
     *
     * @dataProvider getQueryProvider
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvVariableSubstitutionNoVariables(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution no variables - %s',
                $data['language']
            )
        );

        $language   = $this->getCsvConfig()[$data['code']];
        $translator = new Csv(new InterpolatorFactory(), $language);

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->function}(
                $key,
                [
                    'name' => 'my friend',
                ]
            );

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() -
     * variable substitution in string (one variable)
     *
     * @dataProvider getQueryOneVariable
     *
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvVariableSubstitutionOneVariable(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution one variable - %s',
                $data['language']
            )
        );

        $language   = $this->getCsvConfig()[$data['code']];
        $translator = new Csv(new InterpolatorFactory(), $language);

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
     * @param UnitTester $I
     * @param Example    $data
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterCsvVariableSubstitutionTwoVariable(
        UnitTester $I,
        Example $data
    ) {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Csv - variable substitution two variables - %s',
                $data['language']
            )
        );

        $language   = $this->getCsvConfig()[$data['code']];
        $translator = new Csv(new InterpolatorFactory(), $language);
        $vars       = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->function}($key, $vars);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: query() - array access and UTF8
     * strings
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language   = $this->getCsvConfig()['ru'];
        $translator = new Csv(new InterpolatorFactory(), $language);

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
     * @return array[]
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
     * @return array[]
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
     * @return array[]
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
