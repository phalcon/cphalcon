<?php

/**
 * Personers
 *
 * Personers is people in danish
 */
class Personers extends Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'personas';
	}

	public function columnMap()
	{
		return array(
			'cedula' => 'borgerId',
			'tipo_documento_id' => 'slagBorgerId',
			'nombres' => 'navnes',
			'telefono' => 'telefon',
			'direccion' => 'adresse',
			'email' => 'elektroniskPost',
			'fecha_nacimiento' => 'fodtDato',
			'ciudad_id' => 'fodebyId',
			'creado_at' => 'skabtPa',
			'cupo' => 'kredit',
			'estado' => 'status'
		);
	}

}