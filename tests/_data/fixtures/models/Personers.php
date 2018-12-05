<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

class Personers extends Model
{

    public function getSource(): string
    {
        return 'personas';
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
