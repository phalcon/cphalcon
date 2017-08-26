<?php

namespace Phalcon\Test\ModelRepositories;

use Phalcon\Mvc\Model\Repository;

/**
 * \Phalcon\Test\ModelRepositories\PersonersRepository
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\ModelRepositories
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PersonersRepository extends Repository
{
    public function initialize()
    {
        $this->setSource('personas');
    }

    public function columnMap()
    {
        return [
            'cedula'            => 'borgerId',
            'tipo_documento_id' => 'slagBorgerId',
            'nombres'           => 'navnes',
            'telefono'          => 'telefon',
            'direccion'         => 'adresse',
            'email'             => 'elektroniskPost',
            'fecha_nacimiento'  => 'fodtDato',
            'ciudad_id'         => 'fodebyId',
            'creado_at'         => 'skabtPa',
            'cupo'              => 'kredit',
            'estado'            => 'status',
        ];
    }
}
